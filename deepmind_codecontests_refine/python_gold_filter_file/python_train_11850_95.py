#全探索すると終わらない
import math
N, M = map(int, input().split())
ans = 1
    
for i in range((M+N-1)//N, 0, -1):
    if M%i == 0:
        if (M//i)//N >= 1:
            print (i)
            exit()
