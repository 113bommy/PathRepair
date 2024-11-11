def solve(n):
    cnt=0
    if n==1:
        return 0
    while True:
        if n >= 6 and n%6==0:
            n = n//6
            cnt+=1
            if n == 1:
                return cnt
            elif n == 6:
                return cnt+1
            elif n < 6 :
                n*=2
                cnt+=1
                if n%6 ==0:
                    return cnt+1
                else:
                    return -1
        else:
            n*=2
            cnt+=1
            if n%6!=0:
                return -1
 
def main():
    t = int(input())
    for i in range(t):
        print(solve(int(input())))
 
main()