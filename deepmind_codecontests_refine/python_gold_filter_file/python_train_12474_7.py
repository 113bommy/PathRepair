s=input()
w=int(input())
for i in range((len(s)-1)//w+1):
    print(s[i*w],end='')