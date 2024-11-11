def main():
    n = int(input())
    ss = list(zip(input(), range(0,n)))
    prev = ' '
    res = ['0']*n
    for i in range(1, n):
        if ss[i][0] < ss[i-1][0]:
            if res[ss[i-1][1]] == '0':
                res[ss[i][1]] = '1'
            j = i-1
            while j >= 0  and ss[i][0] < ss[j][0]:
                if res[ss[i][1]] == res[ss[j][1]]:
                    print("NO")
                    return
                else:
                    j -= 1
            ss[j+1:i+1] = [ss[i]]+ss[j+1:i]
    print("YES")
    print(''.join(res))





if __name__ == "__main__":
    main()