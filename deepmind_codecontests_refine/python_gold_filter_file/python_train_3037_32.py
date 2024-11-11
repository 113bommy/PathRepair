from sys import stdin,stdout
def main() :
    n = int(stdin.readline())
    arr = [int(i)for i in stdin.readline().split()]
    s = [0] * (n + 1)
    s[0] = arr[0]
    for i in range(1,n) :
        s[i] = s[i - 1] + arr[i]
    q = int(stdin.readline())
    for i in range(q) :
        a,b = stdin.readline().split()
        if int(a) == 1 :
            stdout.write(str(int((s[int(b) - 1])/10)))
            stdout.write("\n")
        else :
            stdout.write(str(int((s[int(b) - 1] - s[int(a) - 2])/10)))
            stdout.write("\n")
if __name__ == "__main__" :
    main()