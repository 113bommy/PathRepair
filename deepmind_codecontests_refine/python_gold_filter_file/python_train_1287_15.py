n = int (input ())
arr = list (map (int, input ().split()))
print (n - (sum (arr) % n != 0))
