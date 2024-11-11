n=int(input())
s=set(map(int,input().split()))
if n<=1:
            print("NO")
else:
            if len(s)==1:
                        print("NO")
            else:
                        b=sorted(s)
                        print(b[1])