s=''.join(sorted(input()))
t=''.join(sorted(input(),reverse=True))
print('YNeos'[s>=t::2])