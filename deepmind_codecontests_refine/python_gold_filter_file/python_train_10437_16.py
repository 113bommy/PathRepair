import math
def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        temp = list(map(int,input().split()))
        c = 0
        
        for j in range(0,len(temp)):
            if j%2==0:
                if temp[j]>0:
                    
                    temp[j] = 0-temp[j]
            else:
                if temp[j]<0:
                    temp[j] = 0 - temp[j]
        print(*temp)
    
    
main()
