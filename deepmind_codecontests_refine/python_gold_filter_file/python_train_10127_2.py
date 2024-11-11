from sys import stdin, stdout, setrecursionlimit
import threading

# tail-recursion optimization
# In case of tail-recusion optimized code, have to use python compiler.
# Otherwise, memory limit may exceed.
# declare the class Tail_Recursion_Optimization
class Tail_Recursion_Optimization:
    def __init__(self, RECURSION_LIMIT, STACK_SIZE):
        setrecursionlimit(RECURSION_LIMIT)
        threading.stack_size(STACK_SIZE)
        return None
        
class SOLVE:
    a = n = q = None
    cnt = 0
    
    def DP(self, pos, sym, dp):
        self.cnt += 1
        if pos == self.n:
            return 0
        
        if dp[pos][sym] != None:
            return dp[pos][sym]
        
        total1 = total2 = 0
        total1 += [-1, 1][sym] * self.a[pos] + self.DP(pos+1, sym^1, dp)
        total2 += self.DP(pos+1, sym, dp)
        dp[pos][sym] = max(total1, total2)
        
        return dp[pos][sym]
    
    def solve(self):
        R = stdin.readline
        #f = open('input.txt');R = f.readline
        W = stdout.write
        
        ans = []
        
        for i in range(int(R())):
            self.n, self.q = [int(x) for x in R().split()]
            self.a         = [int(x) for x in R().split()]
            
            dp = [[None, None] for j in range(self.n)]
            ans.append(str(self.DP(0, 1, dp)))
        
        W('\n'.join(ans))
        return 0
        
def main():
    s = SOLVE()
    s.solve()
Tail_Recursion_Optimization(10**7, 104857600) # recursion-call size, stack-size in byte
threading.Thread(target=main).start()
#main()