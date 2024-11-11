t = int(input())
for _ in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    l=sorted(l)

    if n==1:
        print(0)
    else:
        left=l[0]+l[1]
        right=l[-1]+l[-2]

        def countSums(l,s):
            ans=0
            left=0
            right=len(l)-1

            while left<right:
                if l[left]+l[right]==s:
                    ans+=1
                    left+=1
                    right-=1
                elif l[left]+l[right]>s:
                    right-=1
                else:
                    left+=1
            return ans


        ans=0
        for i in range(left,right+1):
            ans=max(ans,countSums(l,i))
        print(ans)
