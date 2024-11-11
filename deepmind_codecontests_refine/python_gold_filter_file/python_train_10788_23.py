nc,pc=0,0
def point(s):
    global pc
    global nc
    if s[0]!='-':
        nc+=1
    else:
        pc+=1
        
for i in range(int(input())):
    s=input()
    point(s)
if nc<=1 or pc<=1:
    print("YES")
else:
    print("NO")