if __name__ == '__main__':
    import sys
    input = sys.stdin.readline
    test = int(input())
    for i in range(test):
        numbers = list(map(int, input().split()))
        people = numbers[0]
        # the nr of people is odd
        salary = numbers[1]
        interv= []
        nr = 0
        for j in range(people):
            v = list(map(int, input().split()))
            left = v[0]
            right = v[1]
            nr = nr + left
            interv.append([left, right])
        left = 0
        # 10^9 the highest number on the right
        right = 1000000001
        while right > left + 1:
            m = (left + right) // 2
            fin = []
            for j in range(people):
                if m <= interv[j][1]:
                    if -interv[j][0] < -m:
                      fin.append(-m)
                    else:
                      fin.append(-interv[j][0])
            x = len(fin)
            if x < people//2 + 1:
                right = m
                continue
            fin.sort()
            suma = nr + (people//2 + 1) * m + sum(fin[:people//2 + 1])
            if suma > salary:
                right = m
            else:
                left = m
        print(left)




