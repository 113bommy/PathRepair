alph = 'abcdefghijklmnopqrstuvwxyz'

n, k = map(int, input().split())
diff = n - k
mult, rem = diff // 2, diff % 2

print(alph[0:k] + (mult * alph[0:2]) + rem*alph[0])
