favourable = 0
for _ in range(int(input())):
    details = input().split()
    if int(details[1]) - int(details[0]) >= 2:
        favourable+=1
print(favourable)