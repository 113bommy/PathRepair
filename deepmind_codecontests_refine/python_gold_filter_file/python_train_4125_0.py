from sys import stdin

input = stdin.readline

def main():
    
    mod = 10**9 + 7
    n,l,m = map(int,input().split())
    ar = [0 for i in range(m)]
    ar3 = [0 for i in range(m)]
    def f(num):
        return int(num) % m
    def f2(num):
        return num % 1000000007
    ai1 = list(map(f,input().split()))
    ai2 = list(map(f,input().split()))
    ai3 = list(map(f,input().split()))
 
    mm = m**2
    
    ar2 = [0 for i in range(mm)]

    def mult(m1,m2):
        ans = [0 for i in range(mm)]
        m12 = [0 for i in range(m)]
        
        for i in range(m):
            for j in range(m):
                m12[i] += m1[i+j*m] 
        
        for i in range(m):
            for j in range(m):
                temp = (i+j)%m
                for j2 in range(m):
                    ans[temp+j2*m] += m12[i] * m2[j+j2*m]
        ans = list(map(f2,ans))
        return ans
 
    def mult2(m1,m2):
        ans = [0] * m
        
        for i in range(m):
            for j in range(m):
                ans[(i+j)%m] += m1[i] * m2[j]
                
        print(ans[0] % mod)

    def mult3(m1,m2):
        m12 = [0 for i in range(m)]
        
        for i in range(m):
            for j in range(m):
                m12[i] += m1[i+j*m]
                m12[i] %= mod
                
        m22 = [0 for i in range(m)]
        
        for i in range(m):
            for j in range(m):
                m22[i] += m2[i+j*m] 
                m22[i] %= mod
        
        ans = [0 for i in range(mm)]
        for i in range(m):
            for j in range(m):
                ans[(i+j)%m] += m12[i] * m22[j]
                ans[(i+j)%m] %= mod
                
        return ans
    
    def power(number, n):
        n -= 1
        if n == -1:
            return number
        res = number
        number2 = [number[i] for i in range(mm)]
        
        
        while(n):
            if n & 1:
                res = mult3(res,number)
            number = mult3(number,number)
            n >>= 1
        
        return mult(res,number2)

    for i in range(n):
        ar[ai1[i]] += 1
        ar2[ai2[i] + ai3[i]* m] += 1
        ar3[ai2[i]] += 1
        
    if l == 1:
        mult2(ar,ar3)
        return
    ans = power(ar2,l-2)
    ar4 = [0] * m
    for i in range(m):
        for j in range(m):
            ar4[(i+j)%m] += ans[i + j*m]
    mult2(ar,ar4)
main()
