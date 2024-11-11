H,A=map(int,input().split())
n=H//A
if H%A!=0:
    n+=1
print(n)