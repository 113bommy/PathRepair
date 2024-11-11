a=10**9
b=10**9
c=10**9
ac=10**9
bc=10**9
ab=10**9
abc=10**9

n=int(input())
for i in range(n):
    x,y=input().split()
    if(y=='A'):
        a=min(a,int(x))
    if(y=='B'):
        b=min(b,int(x))
    if(y=='C'):
        c=min(c,int(x))
    if(y=='AB' or y=='BA'):
        ab=min(ab,int(x))
    if(y=='AC' or y=="CA"):
        ac=min(ac,int(x))
    if(y=='BC' or y=='CB'):
        bc=min(bc,int(x))  
    if(y=='ABC' or y=='ACB' or y=='BAC' or y=='BCA' or y=='CAB' or y=='CBA'):
        abc=min(abc,int(x))       


ans=min((a+b+c),(a+bc),(abc),(ab+c),(ac+b),(ab+ac),(ab+bc),(ac+bc))
if(ans>10**7):
    print(-1)
else:
    print(ans)





            