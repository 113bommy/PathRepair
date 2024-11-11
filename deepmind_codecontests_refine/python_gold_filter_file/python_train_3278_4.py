import sys
s = sys.stdin.readline().strip()
n = len(s)
e=0
for i in range(n):
    if (ord(s[i])-ord('0'))%8 == 0 and e==0:
        print("YES")
        print(s[i])
        e=1
        break
    for j in range(i+1,n):
        if ((ord(s[i])-ord('0'))*10+(ord(s[j])-ord('0')))%8 == 0 and e==0:
            print("YES")
            print(s[i]+s[j])
            e=1
            break
        for k in range(j+1,n):
            if ((ord(s[i])-ord('0'))*100+(ord(s[j])-ord('0'))*10+(ord(s[k])-ord('0')))%8 == 0 and e==0:
                print("YES")
                print(s[i]+s[j]+s[k])
                e=1
                break
if e == 0:
    print("NO")


