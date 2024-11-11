w, b = map(int, input().split(' '))

if w==0:
    print(0)
elif b==0:
    print(1)
else:
    solved = [[-1]*b for i in range(w)]

    def solve(w, b):
        if solved[w-1][b-1] != -1:
            return solved[w-1][b-1]
        if w==0:
            ans = 0
            solved[w-1][b-1] = ans
            return ans
        
        if b==0:
            ans = 1
            solved[w-1][b-1] = ans
            return ans
        
        if b==1:
            ans = w/(w+1)
            solved[w-1][b-1] = ans
            return ans
        
        if b==2:
            if w==1:
                ans = 1/3
                solved[w-1][b-1] = ans
                return ans
            else:
                ans = w/(w+2) + 2/(w+2) * 1/(w+1)
                solved[w-1][b-1] = ans
                return ans
        
        x = solve(w-1, b-2)
        y = solve(w, b-3)
        
        ans = w/(w+b) + b/(w+b) * (b-1)/(w+b-1) * (w/(w+b-2) * x + (b-2)/(w+b-2) * y)
        solved[w-1][b-1] = ans
        return ans
                    
    print(solve(w, b))                 
