s=input()
n=len(s)
if(len(s)%2):
    print("-1")
    exit()
a=abs(s.count('L')-s.count('R'))
b=abs(s.count('U')-s.count('D'))
print(min(a,b)+int(abs(a-b)//2))