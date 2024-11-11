s = input()
rnB = s.count("B")
rnS = s.count("S")
rnC = s.count("C")

nB, nS, nC = map(int, input().split())
pB, pS, pC = map(int, input().split())
r = int(input())

def get_cost(n):
    B = (rnB*n-nB)*pB
    S = (rnS*n-nS)*pS
    C = (rnC*n-nC)*pC
    return sum([x for x in [B,S,C] if x > 0])

def binary_search():
    low = 0
    high = 10**20
    mid = 0

    while low <= high:
 
        mid = (high + low) // 2
        p = get_cost(mid)
        
        if p < r:
            low = mid + 1
        else:
            high = mid - 1
    return mid    
    


x = binary_search()
if get_cost(x+1) <= r:
    print(x+1)
elif get_cost(x) <= r:
    print(x)
else:
    print(x-1)
