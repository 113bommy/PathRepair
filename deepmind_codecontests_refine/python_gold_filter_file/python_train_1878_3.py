import sys

class Dice:
    def __init__(self, labels):
        self.labels = labels
    def east(self):
        self.labels[0], self.labels[2], self.labels[5], self.labels[3] = self.labels[3], self.labels[0], self.labels[2], self.labels[5]
    def west(self):
        self.labels[0], self.labels[2], self.labels[5], self.labels[3] = self.labels[2], self.labels[5], self.labels[3], self.labels[0]
    def north(self):
        self.labels[0], self.labels[1], self.labels[5], self.labels[4] = self.labels[1], self.labels[5], self.labels[4], self.labels[0]
    def south(self):
        self.labels[0], self.labels[1], self.labels[5], self.labels[4] = self.labels[4], self.labels[0], self.labels[1], self.labels[5]

dice_num = int(input())
dices = []

for _ in range(dice_num):
    dices.append( Dice(list(map(int, input().split()))) )

south_cnt = 0

for d_i1 in range(len(dices)):
    for d_i2 in range(len(dices)):
        if d_i1 == d_i2:
            continue
        dice1 = dices[d_i1]
        dice2 = dices[d_i2]
        for i in range(8):
            for j in range(4):    
                if dice1.labels[0] == dice2.labels[0] and dice1.labels[1] == dice2.labels[1] and dice1.labels[2] == dice2.labels[2] and dice1.labels[3] == dice2.labels[3] and dice1.labels[4] == dice2.labels[4] and dice1.labels[5] == dice2.labels[5]:
                    print("No")
                    sys.exit()

                dice2.south()
                dice2.east()
                dice2.north()

            if south_cnt == 4:
                dice2.east()
            else:
                dice2.south()
                south_cnt += 1
    
print("Yes")

