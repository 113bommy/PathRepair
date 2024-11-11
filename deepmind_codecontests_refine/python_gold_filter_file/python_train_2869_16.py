t=int(input())
while(t):
    s=input()
    if(len(s)<=10):
        print(s)
    else:
        print(s[0],len(s)-2,s[len(s)-1],sep='')
    t=t-1