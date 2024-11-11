#!../../pypyenv/bin/python

class Solution(object):
    def findSeats(self, arr):
        N = len(arr)
        found = False
        for i in range(N):
            if arr[i].find("OO") != -1:
                found = True
                arr[i] = arr[i].replace("OO", "++", 1)
                break
        print("YES" if found else "NO")
        if found: 
            for s in arr: print(s)

def read_input(): # list
    return [int(x) for x in input().split()]

def readStringInput():
    return input()

if __name__ == "__main__":
    n = read_input()[0]
    arr = []
    for i in range(n):
        arr.append(readStringInput())
    sol = Solution()
    sol.findSeats(arr)
    # print(result)
