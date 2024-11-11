def solve(n):
    big = float('inf')
    small = float('-inf')    
    used = 0
    i = 0
    while(True):
        i += 1 
        used = ((2 ** i - 1) * (2 ** i) // 2) 
        # 2 ** (i - 1) * (2 ** i - 1)
        n -= used  
        if n == 0:
            return i
        elif n < 0:
            return i - 1                     

        
    
def main():
    t = int(input())    
    for i in range(t):
        n = int(input())                
        ans = solve(n) 
        print(ans)     
        # for i in ans:
        #     print(i,end = "")
        # print()  
main()

