t=int(input())
for p in range(t):
    s=input()
    s=s.upper()
    ls=[x for x in s]
    pas=False
    if ls.count('A')!=1:
        print("NO")
        continue
    else:
        left_limit=ls.index('A')
        right_limit=ls.index('A')
        for i in range(65+1,65+27):
            if not left_limit and right_limit==len(ls)-1:
                print("YES")
                pas=True
                break
            else:
                if ls.count(chr(i))!=1:
                    print("NO")
                    pas=True
                    break
                if left_limit>0 and ls[left_limit-1]==chr(i):
                    left_limit-=1
                    continue
                elif right_limit<len(ls)-1 and ls[right_limit+1]==chr(i):
                    right_limit+=1
                    continue
                else:
                    print("NO")
                    pas=True
                    break
        if not pas:
            print("NO")
           