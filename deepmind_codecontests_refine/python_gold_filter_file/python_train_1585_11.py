def check(s):
    a = sum(list(map(int, s))) % 2 == 0
    b = int(s[-1]) % 2 != 0
    c = s[0] != '0'
    return a, b, c

def solve(n, s):
    c = check(s) 
    while c[0] == False or c[1] == False or c[2] == False:
        if c[1] == False:
            s = s[0:-1] 
        elif c[0] == False:
            for i in range(0, len(s)-1):
                if int(s[i]) % 2 != 0:
                    s = s[:i] + s [i+1:]
                    break
            else:
                return -1
        elif c[2] == False:
            s = s[1:]
        if s == '0' or s == '':
            return -1
        c = check(s) 
    return s

def main():
    t = int(input())
    for i in range(0, t):
        print(solve(int(input()), input()))

if __name__ == '__main__':
    main()