from sys import stdin, stdout

def main():

    t = int(stdin.readline())

    for _ in range(t):
        l = int(stdin.readline())

        if l < 4:
            stdout.write(str(-1)+'\n')
            continue

        #max_odd = l if l & 1 else l - 1
        #
        #ans = [number for number in range(max_odd, 0, -2)]
        #
        #ans.append(4)
        #ans.append(2)
        #
        #for i in range(6, l + 1, 2):
        #    ans.append(i)
        #
        #stdout.write(' '.join(map(str, ans))+ '\n')

        ans = [3, 1, 4, 2]
        for i in range(5, l + 1):
            if i & 1:
                ans.insert(0, i)
            else:
                ans.append(i)
        stdout.write(' '.join(map(str, ans))+ '\n')

if __name__ == "__main__":
    main()