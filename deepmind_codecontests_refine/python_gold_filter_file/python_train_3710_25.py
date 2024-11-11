import math
inp = input().split(" ")
health = int(inp[0])
attack = int(inp[1])
potion = int(inp[2])
inp = input().split(" ")
monsterhealth = int(inp[0])
monsterattack = int(inp[1])
attacksneeded = math.ceil(monsterhealth / attack)
healsneeded = 0
while healsneeded * potion + health <= monsterattack * (attacksneeded - 1 + healsneeded):
    healsneeded = healsneeded + 1
print(healsneeded + attacksneeded)
for i in range(0, healsneeded):
    print("HEAL")
for i in range(0, attacksneeded):
    print("STRIKE")
