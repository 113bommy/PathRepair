def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)
    return divisors
n=int(input())
l1=make_divisors(n-1)
l2=make_divisors(n)[2:]
for i in l2:
  j=n/i
  while j%i==0:
    j/=i
  if j%i==1 and n/i not in l1:
    l1.append(n/i)
print(len(l1))