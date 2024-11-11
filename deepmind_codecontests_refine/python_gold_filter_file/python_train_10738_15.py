from sys import stdin,stdout


def solve(arr,minDiff):
    arr = sorted(arr)

    # print(arr)
    l = 0
    if len(arr) % 2 == 0:
        r = len(arr)//2
        rr = len(arr)//2
    else: 
        r = (len(arr)//2)
        rr = (len(arr)//2)
    counter = 0
    # print(arr[l])
    # print(arr[r])

    i=0
    while  i < r and rr < len(arr):
        # print(arr[rr],arr[i])
        if arr[rr]-arr[i] >= minDiff:
            counter+=1
            i+=1
        rr += 1
        
    return counter

if __name__ == "__main__":
    n,z = map(int, input().split())
    ar = [int(x) for x in input().split()]

    stdout.write(str(solve(ar,z)))

    #print(solve([9, 10, 100, 1002, 1023],10))