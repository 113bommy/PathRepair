def main():
   n, s  = map(int,input().split())
   y = [i for i in range(s, s+180) if i - sum([int(j) for j in str(i)]) >= s]
   a = y[0]
   print(max(n-a+1,0))
#   print(max(n - [i for i in range(s, s + 180) if i - sum([int(j) for j in str(i)]) >= s][0] + 1, 0))

if __name__ == "__main__":
    main()
