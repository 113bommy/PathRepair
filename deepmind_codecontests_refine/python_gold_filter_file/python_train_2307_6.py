from bisect import bisect_left

def solve():
    N = int(input())
    A = [abs(int(k)) for k in input().split()]
    
    A.sort()
    
    ans = 0
    
    for i in range(N-1):
        pos = bisect_left(A, 2*A[i])
        
        if pos == N or A[pos] > 2*A[i]:
            pos -= 1

        if pos < N-1 and A[pos] == A[pos+1]:
            pos += 1
    
        if pos > i:
            ans += (pos - i)
    
    print (ans)        
    
if __name__ == "__main__":  
    solve()
    