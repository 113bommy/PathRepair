s,t=map(lambda x:sorted(x.count(i)for i in set(x)),open(0))
print('YNeos'[s!=t::2])