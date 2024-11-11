n=int(input())
cnt=0
l=['3','5','7']
def sol(x,c):
    global cnt
    if int(x)<=n and all(y in x for y in l):
        cnt+=1
    if c<9:
        for y in l:
            sol(x+y,c+1)
sol('0',0)
print(cnt)