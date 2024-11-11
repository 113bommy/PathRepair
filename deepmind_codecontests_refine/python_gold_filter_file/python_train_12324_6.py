x = 0
limit = int(input())
count = 0
while limit > count:
    user = input()
    if (user == "++X") or (user == "X++"):
        x += 1  
    elif (user == "--X") or (user =="X--"):
        x -= 1
    count += 1
print(x)