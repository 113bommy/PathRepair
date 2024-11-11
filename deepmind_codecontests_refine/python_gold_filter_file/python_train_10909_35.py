n=int(input())
s=input()
sm=0
for x in [(x,y,z) for x in range(10) for y in range(10) for z in range(10)]:
    token=0
    for i in range(n):
        if x[token]==int(s[i]):
            token+=1
            if token==3 : break
    if token==3 : sm+=1
print(sm)