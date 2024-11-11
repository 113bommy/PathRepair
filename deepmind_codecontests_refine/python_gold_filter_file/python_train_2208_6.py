import math
t=int(input())
for i in range(t):
    s=input()
    n=len(s)
    p = s.count('one')+s.count('two')-s.count('twone')
    print(p)
    if p==0:
        print()
    else:
        j=0
        while(j<(n-2)):
            if s[j]=='o' and s[j+1]=='n' and s[j+2]=='e':
                print(j+2,end=" ")
                j+=3
            elif j<(n-4) and s[j]=='t' and s[j+1]=='w' and s[j+2]=='o' and s[j+3]=='n' and s[j+4]=='e':
                print(j+3,end=" ")
                j+=5
            elif s[j]=='t' and s[j+1]=='w' and s[j+2]=='o':
                print(j+2,end=" ")
                j+=3
            else:
                j+=1
        print()