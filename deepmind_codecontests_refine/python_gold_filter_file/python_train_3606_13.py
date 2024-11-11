input()
prnt=-10000000
for x in list(map(int,input().split())):
     if x>=0:
          prnt=max(prnt, x) if int(abs(x)**0.5)**2 != abs(x) else prnt
     else:
          prnt = max(prnt,x)
print(prnt)
