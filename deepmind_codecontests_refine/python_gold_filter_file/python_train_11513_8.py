
n,k = map(int,input().split())
alpha = 'abcdefghijklmnopqrstuvwxyz' 
repeat = ((n-k) // k) +1
part = ((n-k) % k) 
word = alpha[:k]
print(word * repeat + word[:part])
