n=int(input())
x=0
for i in range(0, n):
    string=input().split()
    p=int(string[0]); q=int(string[1])
    if((q-p)>=2):
        x+=1
print(x)
