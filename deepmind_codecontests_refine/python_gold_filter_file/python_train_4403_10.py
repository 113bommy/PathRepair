from sys import stdin,stdout


ans = []
def main():
    n = int(stdin.readline())
    arr = list(map(int,stdin.readline().split()))
    start = arr.index(1)
    end = n - arr[::-1].index(1)
    count = 0
    # print(start, end)
    for item in arr[start:end]:
        if item == 0:
            count += 1
    ans.append(str(count))
    return



if __name__== '__main__':
    for i in range(int(stdin.readline())):
        main()

    stdout.write('\n'.join(ans))
