n=int(input())
t=0
for i in range(n):
    s=input()
    if s=='++X' or s=='X++':
        t+=1
    elif s=='X--' or s=='--X':
        t-=1
print(t)
