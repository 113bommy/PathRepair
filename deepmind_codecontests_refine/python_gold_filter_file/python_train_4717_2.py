
import math

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        miners = []
        mines = []
        for _ in range(2*n):
            point = list(map(int, input().split()))
            if point[0]== 0:
                miners.append(point)
            else:
                mines.append(point)
        #print(mines)
        #print(miners)

        miners.sort(key= lambda x:abs(x[1]))
        mines.sort(key = lambda x:abs(x[0]))

        #print(mines)
        #print(miners)

        min_energy = 0

        for i in range(n):
            min_energy+= math.sqrt(miners[i][1]*miners[i][1] + mines[i][0]*mines[i][0])

        print(min_energy)

if __name__ == "__main__":
    main()