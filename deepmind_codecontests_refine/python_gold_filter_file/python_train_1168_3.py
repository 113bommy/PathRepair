import sys
input = sys.stdin.readline
for ti in range(int(input())):
    a, b, p = [int(x) for x in input().strip().split()]
    c = {'A':a, 'B':b}
    s = input().strip()
    prev, cur = len(s)-2, len(s)-3
    if(c[s[-2]]>p):
        print(len(s))
        continue
    p-=c[s[-2]]
    while(cur>=0):
        if(s[cur] == s[prev]):
            cur -= 1
            prev -= 1
        else:
            if(p>=c[s[cur]]):
                p -= c[s[cur]]
                cur -= 1
                prev -= 1
            else:
                break
    print(prev+1)
        
        
