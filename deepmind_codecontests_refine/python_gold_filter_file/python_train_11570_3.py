a=[2,3,4,5,6,7]
x=input()
t=0
R=[]
while t<int(x):
    y=int(input())
    rounds=0
    if y>7:
        if y%7!=0:
            rounds=y//7 +1
        else:
            rounds=y//7
    else:
         rounds=1
    R.append(rounds)
    t+=1
for r in R:
    print(r)