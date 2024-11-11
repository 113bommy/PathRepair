def solve(num):
    str1 = list(str(num))

    if num == 1:
        return 'YES'
    elif num > 1 and num < 11:
        return 'NO'

    prevPrev = str1[0]
    prev = str1[1]

    

    if prevPrev != '1':
        return 'NO'

    if prev != '1' and prev != '4':
        return 'NO'
    
    length = len(str1)

    for i in range(2, length):

        current = str1[i]
        temp14 = prev + current
        temp144 = prevPrev + prev + current

        if current != '1' and temp14 != '14' and temp144 != '144':
            return 'NO' 

        prevPrev = prev
        prev = current

    return 'YES'


if __name__ == "__main__":
    num = int(input())
    ans = solve(num)
    print(ans)

# solve(1141441)