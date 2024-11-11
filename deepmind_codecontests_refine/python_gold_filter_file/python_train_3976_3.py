import math
def get_n(charactor):
    S, I, P = charactor
    low = max(0, math.ceil((I-S+P+0.01)/2))
    if P==0 and S > I:
        return 1
    else:
        return len(range(low, P+1))
 
T = int(input())
for i in range(T):
    charactor = map(int, input().split())
    print(get_n(charactor))