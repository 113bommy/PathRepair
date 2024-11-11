# https://codeforces.com/gym/298388/problem/A


def checkDiverse(arr):
    arr = list(arr)
    arr_codes = [ ord(x) for x in set(list(arr))]

    if(len(arr_codes) != len(arr)):
        return False

    # print(arr_codes)
    big = max(arr_codes)
    small = min(arr_codes)
    # print('Big ',big)
    # print('Small ',small)
    # print('Len ',len(arr_codes))
    if(big-small+1 == len(arr)):
        return True
    return False



# print('hello world')
tc = int(input())
# # print(tc)
while tc > 0:
    string = input()
    isYes = checkDiverse(string)
    if isYes:
        print('Yes')
    else:
        print('No')

    tc -=1
    # print('TC ', tc)



# print(checkDiverse('snmmnmkgkhhhg'))
