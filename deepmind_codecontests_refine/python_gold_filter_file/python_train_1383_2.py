def main():
    t = int(input())
    for _ in range(t):
        s = input(); n = len(s)
        stored = num_as = total = 0
        for i in range(n - 1, -1, -1):
            if s[i] == "B":
                stored += 1
            else:
                num_as += 1
                if stored:
                    stored -= 1
                    total += 1
        num_bs = n - num_as
        if stored:
            total += (num_bs - total) // 2
        print(n - total * 2)
main()