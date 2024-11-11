#question3
import sys
from math import *
import builtins

input = sys.stdin.readline


def print(x, end='\n'):
    sys.stdout.write(str(x) + end)


# IO helpers
def get_int():
    return int(input())


def get_list_ints():
    return list(map(int, input().split()))


def get_char_list():
    s = input()
    return list(s[:len(s) - 1])


def get_tuple_ints():
    return tuple(map(int, input().split()))


def print_iterable(p):
    print(" ".join(map(str, p)))


def binary_search(arr, x):
    low = 0
    high = len(arr) - 1
    mid = 0
    while low <= high:
        mid = (high + low) // 2
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid
    return high
def wood(listc,l):
    if l==1:
        return 1
    elif l==2:
        return 2
    else:
        stay=[0,1]
        if listc[1][0]-listc[0][0]>listc[1][1]:
            left=[1,2]
        else:
            left=[1,1]
        right=[1,2]
        for i in range(2,l):
            if listc[i][0]-listc[i-1][0]<=listc[i][1]:
                left.append(0)
                if listc[i][0]-listc[i-1][0]>listc[i-1][1]:
                    right.append(max(stay[i-1],left[i-1],right[i-1])+1)
                    stay.append(max(stay[i-1],left[i-1],right[i-1]))
                else:
                    right.append(max(stay[i-1],left[i-1])+1)
                    stay.append(max(stay[i-1],left[i-1]))
            elif listc[i][0]-listc[i-1][0]>listc[i-1][1]+listc[i][1]:
                left.append(max(stay[i-1],left[i-1],right[i-1])+1)
                right.append(max(stay[i-1],left[i-1],right[i-1])+1)
                stay.append(max(stay[i-1],left[i-1],right[i-1]))
            else:
                left.append(max(stay[i-1],left[i-1])+1)
                if listc[i][0]-listc[i-1][0]>listc[i-1][1]:
                    right.append(max(stay[i-1],left[i-1],right[i-1])+1)
                    stay.append(max(stay[i-1],left[i-1],right[i-1]))
                else:
                    right.append(max(stay[i-1],left[i-1])+1)
                    stay.append(max(stay[i-1],left[i-1]))
        return(max(stay[-1],left[-1],right[-1]))




def main(): 
    n=get_int()
    alist=[]
    for i in range(n):
        alist.append(get_list_ints())
    print(wood(alist,n))
    pass
    
if __name__ == '__main__':
    main()