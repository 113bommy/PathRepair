#Codeforce 658A
n,c=(int(v) for v in input().split())
score=[int(u) for u in input().split()]
time=[int(t) for t in input().split()]
Limak=0
Radewoosh=0
tL=0
tR=0
for i in range(n):
    tL += time[i]
    Limak += max(0,(score[i] - c*tL))
    tR += time[n-1-i]
    Radewoosh += max(0,(score[n-1-i] - c*tR))
if Limak > Radewoosh:
    print("Limak")
elif Radewoosh > Limak:
    print("Radewoosh")
else:
    print("Tie")