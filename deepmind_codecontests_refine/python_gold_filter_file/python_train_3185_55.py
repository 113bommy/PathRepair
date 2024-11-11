date = input().split()
limak = int(date[0])
bob = int(date[1])
years = 0

while limak <= bob:
    years += 1
    limak = limak * 3
    bob = bob * 2

print(years)
