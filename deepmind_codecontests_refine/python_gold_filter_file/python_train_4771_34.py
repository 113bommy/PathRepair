def s(n,p):
  while n>0:yield n%p;n//=p
c=lambda*a:sum(s(*a));n=int(input());print(min(c(i,6)+c(n-i,9)for i in range(n+1)))