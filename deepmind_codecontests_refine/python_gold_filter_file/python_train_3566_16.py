for t in range(int(input())):
    n = int(input())
    A = input().split(' ')
    for j in range(n):
        A[j] = int(A[j])
    k = int((n-1)/2)
    evfree = [0]
    evnon = [0]
    odfree = [0]
    odnon = [0]
    for i in range(k):
        evnon.append(max(evnon[i]-A[2*i]+A[2*i+1],0))
        odnon.append(max(odnon[i]-A[2*i+2]+A[2*i+1],0))
        evfree.append(max(evfree[i],evnon[i+1]))
        odfree.append(max(odfree[i],odnon[i+1]))
    x = evfree[k]
    if n%2 == 0:
        evnon.append(max(evnon[k]-A[2*k]+A[2*k+1],0))
        x = max(evfree[k],evnon[k+1])
    ans = 0
    for i in range(k+1):
        ans += A[2*i]
    print( ans + max(x,odfree[k]))
