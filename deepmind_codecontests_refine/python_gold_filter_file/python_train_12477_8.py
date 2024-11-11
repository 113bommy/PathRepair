X=int(input())
d=0
for i in range(1,X+1):
    d+=i
    if d>=X:
        print(i)
        exit()