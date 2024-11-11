def question3():
    N,M = map(int,input().split())
    mod = 1000000007
    arr = [set([]) for i in range(M)]
    for i in range(N):
        name = input()
        for j in range(M):
            arr[j].add(name[j])
    ans = 1       
    # print(arr)    
    for i in range(M):
        ans =  (ans%mod)*(len(arr[i])%mod)
    return ans % mod 
        
        
        
    
    
# remained_test_case = int(input())
remained_test_case = 1
while remained_test_case > 0:
    print(question3())
    remained_test_case -= 1 