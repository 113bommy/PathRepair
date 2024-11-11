import bisect

def main():
    n = int(input())
    beacons = []
    coords = []
    for i in range(n):
        a,b = map(int,input().split())
        beacons.append((a,b))
        coords.append(a)

    if n == 1:
        print(0)
        return
    
    coords.sort()
    beacons.sort()
    dp = [0]*n
    min_val = float('inf')
    for i in range(1,n):
        a,b = beacons[i]
        x_left = a-b-1
        index = bisect.bisect(coords,x_left)
        if index-1 >= 0:
            dp[i] = dp[index-1]+i-index
        else:
            dp[i] = i

        min_val = min(min_val,dp[i]+n-i-1)

    #print(dp)
    print(min_val)
    

main()
