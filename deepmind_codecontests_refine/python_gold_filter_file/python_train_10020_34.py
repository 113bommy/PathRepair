t=int(input())
for _ in range(t):
    n,x=[int(c) for c in input().split()]
    degree=[0 for i in range(n+1)]
    edges={i:[] for i in range(1,n+1)}
    for i in range(n-1):
        a,b=[int(c) for c in input().split()]
        degree[a]+=1
        degree[b]+=1
        edges[a].append(b)
    # #now dp[i] will say if whoever is starting now will win if i is the special node
    # #ofcourse dp[i] = True for all the leaves
    
    # dp=[False for i in range(n+1)]
    
    # for i in range(1,len(degree)):
    #     if degree[i] <= 1:
    #         dp[i] = True
    
     
    if degree[x] <= 1 :
        # print("Hellooo")
        print("Ayush")
    else:
        if ((n - 1) % 2 )== 0:
            print("Ashish")
        else:
            print("Ayush")
        