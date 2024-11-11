def can_invert(n, nums):
    inv = False
    start = -1
    curr = False
    range = ''
    i = 1
    while i < n:
        if nums[i] < nums[i-1]:
            if inv:
                return ''
            elif start == -1:
                start = i
                curr = True
                i+=1
            elif i == n-1:
                if start == 1:
                    range+=str(start) + ' ' + str(i+1)
                elif nums[i] > nums[start-2]:
                    range+=str(start) + ' ' + str(i+1)
                else:
                    range = ''
                return range
            else:
                i+=1
        elif curr:
            if nums[i] < nums[start-1]:
                return ''
            elif start == 1:
                range = str(start) + ' ' + str(i)
                curr = False
                inv = True
                i+=1
            elif nums[i-1] > nums[start-2]:
                range = str(start) + ' ' + str(i)
                curr = False
                inv = True
                i+=1
            else:
                return ''
        else:
            i+=1
    if inv:
        return range
    elif curr:
        return '1 2'
    else:
        return '1 1'


def main():
    n = int(input())
    nums = [int(i) for i in input().split()]
    ans = can_invert(n,nums)
    if ans == '':
        print("no")
    else:
        print("yes\n" + ans)

main()
